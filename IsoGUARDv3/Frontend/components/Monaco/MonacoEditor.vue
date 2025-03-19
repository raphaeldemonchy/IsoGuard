<!-- /components/MonacoEditor.vue -->
<template>
    <div v-if="isClient" ref="editorContainer" class="h-full w-full"></div>
  </template>
  
  <script setup>
  import { ref, onMounted, onBeforeUnmount } from 'vue'
  
  // Vérification côté client
  const isClient = typeof window !== 'undefined'
  let editorInstance = null
  const editorContainer = ref(null)
  
  if (isClient) {
    const monaco = await import('monaco-editor')
  
    onMounted(() => {
      if (editorContainer.value) {
        editorInstance = monaco.editor.create(editorContainer.value, {
          value: '// Commence à coder ici',
          language: 'javascript',
          theme: 'hs-dark',
          fontSize: 14,
          minimap: { enabled: false }
        })
      }
    })
  
    onBeforeUnmount(() => {
      if (editorInstance) {
        editorInstance.dispose()
      }
    })
  }
  </script>
  
  <style scoped>
  .editorContainer {
    height: 100%;
    width: 100%;
  }
  </style>
  