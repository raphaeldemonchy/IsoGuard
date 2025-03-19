export default defineI18nConfig(() => ({
    legacy: false,
    locale: 'en',
    fallbackLocale: 'en',
    lazy: true,
    langDir: 'locales/',
    locales: [
        { code: 'en', file: 'en.json' },
        { code: 'fr', file: 'fr.json' },
    ],
}))
