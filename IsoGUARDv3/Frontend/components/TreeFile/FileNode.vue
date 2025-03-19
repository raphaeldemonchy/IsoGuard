<template>
    <li>
      <div @click="handleClick" class="flex items-center cursor-pointer">
        <span v-if="node.type === 'folder'" class="material-icons-outlined">
          {{ isOpen ? 'folder_open' : 'folder' }}
        </span>
        <span v-if="node.type === 'file'" class="material-icons-outlined">
          insert_drive_file
        </span>
        <span>{{ node.name }}</span>
      </div>
  
      <ul v-if="node.type === 'folder' && isOpen" class="pl-4">
        <TreeNode
          v-for="(child, index) in node.children"
          :key="index"
          :node="child"
          @file-clicked="handleFileClick"
        />
      </ul>
    </li>
  </template>
  
  <script setup>
  import { ref } from 'vue'
  
  const props = defineProps({
    node: Object
  })
  
  const isOpen = ref(false)
  
  const handleClick = () => {
    if (props.node.type === 'folder') {
      isOpen.value = !isOpen.value
    } else {
      emit('file-clicked', props.node.name)
    }
  }
  </script>
  
  <style scoped>
  li {
    list-style-type: none;
    padding: 5px 0;
  }
  
  .cursor-pointer {
    cursor: pointer;
  }
  </style>
  