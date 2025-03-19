<template>
    <div class="file-tree-container p-4 overflow-auto">
      <ul class="space-y-2">
        <FileNode :node="fileStructure" />
      </ul>
    </div>
  </template>
  
  <script setup>
  import { ref } from 'vue'
  import FileNode from '~/components/TreeFile/FileNode.vue'
  
  const fileStructure = ref([
    {
      name: "src",
      type: "folder",
      children: [
        { name: "index.js", type: "file" },
        { name: "App.vue", type: "file" },
        {
          name: "components",
          type: "folder",
          children: [
            { name: "Header.vue", type: "file" },
            { name: "Footer.vue", type: "file" }
          ]
        }
      ]
    },
    {
      name: "assets",
      type: "folder",
      children: [
        { name: "logo.png", type: "file" },
        { name: "style.css", type: "file" }
      ]
    },
    { name: "README.md", type: "file" }
  ])
  </script>
  
  <style scoped>
  .file-tree-container {
    background-color: #f7fafc;
    border-radius: 8px;
    box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
  }
  
  ul {
    list-style-type: none;
    padding-left: 20px;
  }
  </style>
  