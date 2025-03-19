<template>
  <div class="h-[850px] w-full flex flex-col mt-[-40px] border border-white">

    <!-- PROFILE SECTION -->
    <div class="h-[380px] w-full bg-custom-violet flex items-center justify-center">
      <!-- PICTURE PROFILE CONTAINER -->
    
    </div>

    <!-- Textes interactifs -->
    <div class="w-full h-16 flex items-center space-x-10 px-5">
      <div
        v-for="(text, index) in texts"
        :key="index"
        :class="{
          'cursor-pointer text-black text-lg ml-60 font-bold': true,
          'border-b-4 border-blue-500 ml-60': selectedText === text
        }"
        @click="selectText(text)"
      >
        {{ text }}
      </div>
    </div>

    <!-- Contenu dynamique -->
     <!-- Page MODULE COMPLETE -->
    <div class="h-[350px] mt-6 p-4 bg-gray-100" v-if="selectedText">
      <div v-if="selectedText === 'Completed Modules'" class="h-full overflow-y-auto">
        <div class="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-4 p-4">
          <div
            v-for="module in completedModules"
            :key="module.id"
            class="p-4 bg-white rounded shadow-md flex flex-col space-y-2"
          >
            <h3 class="text-lg font-bold text-gray-800">{{ module.name }}</h3>
            <p class="text-sm text-gray-600">{{ module.description }}</p>
            <span class="text-blue-500 font-semibold">Level: {{ module.level }}</span>
          </div>
        </div>
      </div>      
      <!-- Page BADGE -->
      <div v-if="selectedText === 'Badges'" class="h-full overflow-y-auto">
        <div class="grid grid-cols-3 sm:grid-cols-4 md:grid-cols-5 lg:grid-cols-6 gap-4 p-4">
          <div
            v-for="badge in badgeList"
            :key="badge.id"
            class="flex flex-col items-center"
          >
            <img :src="badge.icon" :alt="badge.name" class="w-16 h-16 object-cover" />
            <p class="text-gray-800 text-sm font-medium mt-2">{{ badge.name }}</p>
          </div>
        </div>
      </div>
      <!-- Page ACTIVITY -->
      <p v-if="selectedText === 'Activity'">Contenu pour le Text 3</p>
    </div>

  </div>
</template>

<script setup>
import { ref } from 'vue'
import ProfilePicture from '~/components/ProfilePicture/ProfilePicture.vue'

const selectedText = ref("Completed Modules")
const texts = ['Completed Modules', 'Badges', 'Activity']

const completedModules = ref([
  { id: 1, name: 'Découvert AI', description: 'Description du module 1', level: 'Beginner' },
  { id: 2, name: 'Script Basic', description: 'Description du module 2', level: 'Intermediate' },
  { id: 3, name: 'Farming', description: 'Description du module 3', level: 'Advanced' },
  { id: 4, name: 'Fight', description: 'Description du module 4', level: 'Beginner' },
  { id: 5, name: 'Premier Script', description: 'Description du module 5', level: 'Intermediate' },
])

const badgeList = ref([
  { id: 1, name: 'AI newbies', icon: '/badge/b1.png' },
  { id: 2, name: 'Best Farmer', icon: '/badge/b2.png' },
  { id: 3, name: 'Real Tony Stark', icon: '/badge/b3.png' },
  { id: 4, name: 'Script Genius', icon: '/badge/b4.png' },
  { id: 5, name: 'AI Master', icon: '/badge/b5.png' },
  { id: 6, name: 'Nice Mate', icon: '/badge/b6.png' },
])


const selectText = (text) => {
  selectedText.value = text
}
</script>

<style scoped>
.bg-custom-violet {
  background-color: #3E3A7D;
}

.bg-custom2 {
  background-color: #24194F;
}

.text-custom3 {
  color: #48CEFF;
}

::selection {
  background-color: rgba(0, 0, 255, 0.3);
  color: #fff;
}
</style>
