<script setup lang="ts">
import { useI18n } from 'vue-i18n';

const { locale, setLocale } = useI18n();

const toggleLocale = () => {
  setLocale(locale.value === 'en' ? 'fr' : 'en');
};
</script>

<template>
  <UButton
      color="gray"
      variant="ghost"
      aria-label="Locale"
      :icon="locale === 'en' ? 'material-symbols:language-us-rounded' : 'material-symbols:language-french-rounded'"
      @click="toggleLocale"
  />
</template>
