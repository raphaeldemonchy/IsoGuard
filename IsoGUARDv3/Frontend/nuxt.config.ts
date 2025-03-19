// https://nuxt.com/docs/api/configuration/nuxt-config
export default defineNuxtConfig({
  modules: [
    '@nuxt/ui',
    '@nuxtjs/i18n',
    '@nuxt/eslint',
    '@nuxt/content',
    '@nuxthq/studio'
  ],
  i18n: {
    lazy: true,
    langDir: 'locales/',
    defaultLocale: 'en',
    locales: [
      { code: 'en', file: 'en.json', name: 'English' },
      { code: 'fr', file: 'fr.json', name: 'Français' },
    ],
  },
  compatibilityDate: '2024-04-03',
  devtools: { enabled: true }
})