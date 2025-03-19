
// @ts-nocheck


export const localeCodes =  [
  "en",
  "fr"
]

export const localeLoaders = {
  "en": [{ key: "../locales/en.json", load: () => import("../locales/en.json" /* webpackChunkName: "locale__home_uknown_Bureau_Capstone_V2_IsoGuard_IsoGUARDv3_Frontend_locales_en_json" */), cache: true }],
  "fr": [{ key: "../locales/fr.json", load: () => import("../locales/fr.json" /* webpackChunkName: "locale__home_uknown_Bureau_Capstone_V2_IsoGuard_IsoGUARDv3_Frontend_locales_fr_json" */), cache: true }]
}

export const vueI18nConfigs = [
  () => import("../i18n.config.ts?hash=bffaebcb&config=1" /* webpackChunkName: "i18n_config_bffaebcb" */)
]

export const nuxtI18nOptions = {
  "experimental": {
    "localeDetector": "",
    "switchLocalePathLinkSSR": false,
    "autoImportTranslationFunctions": false
  },
  "bundle": {
    "compositionOnly": true,
    "runtimeOnly": false,
    "fullInstall": true,
    "dropMessageCompiler": false
  },
  "compilation": {
    "jit": true,
    "strictMessage": true,
    "escapeHtml": false
  },
  "customBlocks": {
    "defaultSFCLang": "json",
    "globalSFCScope": false
  },
  "vueI18n": "",
  "locales": [
    {
      "code": "en",
      "name": "English",
      "files": [
        "/home/uknown/Bureau/Capstone/V2/IsoGuard/IsoGUARDv3/Frontend/locales/en.json"
      ]
    },
    {
      "code": "fr",
      "name": "Français",
      "files": [
        "/home/uknown/Bureau/Capstone/V2/IsoGuard/IsoGUARDv3/Frontend/locales/fr.json"
      ]
    }
  ],
  "defaultLocale": "en",
  "defaultDirection": "ltr",
  "routesNameSeparator": "___",
  "trailingSlash": false,
  "defaultLocaleRouteNameSuffix": "default",
  "strategy": "prefix_except_default",
  "lazy": true,
  "langDir": "locales/",
  "detectBrowserLanguage": {
    "alwaysRedirect": false,
    "cookieCrossOrigin": false,
    "cookieDomain": null,
    "cookieKey": "i18n_redirected",
    "cookieSecure": false,
    "fallbackLocale": "",
    "redirectOn": "root",
    "useCookie": true
  },
  "differentDomains": false,
  "baseUrl": "",
  "dynamicRouteParams": false,
  "customRoutes": "page",
  "pages": {},
  "skipSettingLocaleOnNavigate": false,
  "types": "composition",
  "debug": false,
  "parallelPlugin": false,
  "multiDomainLocales": false,
  "i18nModules": []
}

export const normalizedLocales = [
  {
    "code": "en",
    "name": "English",
    "files": [
      {
        "path": "/home/uknown/Bureau/Capstone/V2/IsoGuard/IsoGUARDv3/Frontend/locales/en.json"
      }
    ]
  },
  {
    "code": "fr",
    "name": "Français",
    "files": [
      {
        "path": "/home/uknown/Bureau/Capstone/V2/IsoGuard/IsoGUARDv3/Frontend/locales/fr.json"
      }
    ]
  }
]

export const NUXT_I18N_MODULE_ID = "@nuxtjs/i18n"
export const parallelPlugin = false
export const isSSG = false

export const DEFAULT_DYNAMIC_PARAMS_KEY = "nuxtI18n"
export const DEFAULT_COOKIE_KEY = "i18n_redirected"
export const SWITCH_LOCALE_PATH_LINK_IDENTIFIER = "nuxt-i18n-slp"
