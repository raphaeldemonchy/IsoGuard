<template>
    <div class="flex flex-col items-center">
      <div class="relative">
        <img
          :src="profilePictureUrl"
          alt="Photo de profil"
          class="w-48 h-48 rounded-full object-cover border-4 border-gray-300"
        />
        <button
          @click="triggerFileInput"
          class="absolute bottom-0 right-0 bg-blue-500 text-white rounded-full p-2"
        >
          <i class="bi bi-pencil"></i>
        </button>
      </div>
  
      <input
        type="file"
        ref="fileInput"
        class="hidden"
        accept="image/*"
        @change="onFileChange"
      />
  
      <p v-if="error" class="text-red-500 text-sm">{{ error }}</p>
    </div>
  </template>
  
  <script setup>
  import { ref } from 'vue'
  
  const profilePictureUrl = ref('https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png');
  const fileInput = ref(null)
  const error = ref('')
  
  const triggerFileInput = () => {
    fileInput.value.click()
  }
  
  const onFileChange = async (event) => {
    const file = event.target.files[0]
    if (file) {
      const reader = new FileReader()
  
      reader.onloadend = () => {
        profilePictureUrl.value = reader.result
      }
  
      reader.onerror = () => {
        error.value = 'Erreur de téléchargement de l\'image.'
      }
  
      reader.readAsDataURL(file)
  
    }
  }
  </script>
  
  <style scoped>
  </style>
  