<template>
    <div class="h-[800px] w-full flex mt-[-20px]">
      <div class="max-h-screen w-3/5 border border-gray-500 rounded-xl m-5">
        <!-- <img :src="imageSrc" alt="Game Screenshot" class="w-full h-full object-cover rounded-xl" /> -->
      </div>

      <div class="max-h-screen w-1/12 border border-gray-500 rounded-xl mt-5 mb-5">
      </div>

      <div class="max-h-screen w-1/3 border border-gray-500 rounded-xl m-5 overflow-hidden p-2">
      </div>
    </div>
</template>

<script setup>
    import MonacoEditor from '~/components/Monaco/MonacoEditor.vue'
    import TreeFile from '~/components/TreeFile/TreeFile.vue';
    import imageSrc from '@/assets/images/game.png'
</script>

<style scoped>
    h1 {
      color: #333;
    }
</style>
