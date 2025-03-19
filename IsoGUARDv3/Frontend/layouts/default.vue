<script setup lang="ts">
  import "../global.css";

</script>

<template>
  <div class="min-h-screen flex flex-col bg-white dark:bg-slate-900">
    <header class="sticky top-0 left-0 w-full h-20 z-50 bg-transparent -mb-px backdrop-blur border-b border-purple-500 dark:border-gray-800">
      <nav class="w-full px-2 sm:px-4 lg:px-8 flex items-center justify-between h-full">
        <!-- Left : Title "Code & Conquer" -->
        <div class="flex items-center ml-5">
          <img src="/static/images/logoGN.svg" alt="Logo Groupe Networks" class="h-12" />
          <h1 class="font-bold">ISOGUARD</h1>
        </div>

        <!-- Center : Nav Button -->
        <div class="flex items-center space-x-10">
          <h3><a href="/" class="text-gray-700 dark:text-gray-200 hover:text-orange-500 font-light">Home</a></h3>
          <h3><a href="/sandbox" class="text-gray-700 dark:text-gray-200 hover:text-orange-500 font-light">Sandbox</a></h3>
          <h3><a href="/library" class="text-gray-700 dark:text-gray-200 hover:text-orange-500 font-light">Library</a></h3>
        </div>

        <!-- Right : Icônes et boutons -->
        <div class="flex items-center space-x-2 mr-10">
          <color-mode-button />
          <UButton
          :to="'/profile'"
            color="gray"
            variant="ghost"
            aria-label="Github"
            icon="i-bi:github"
          />
          <local-button />
        </div>

      </nav>
    </header>

    <main class="flex-1 mt-8 p-4 bg-white dark:bg-slate-900">
      <slot />
    </main>
  </div>
</template>
