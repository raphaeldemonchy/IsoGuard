import type { Config } from 'tailwindcss';

export default <Partial<Config>>{
};

module.exports = {
    theme: {
      extend: {
        colors: {
          'custom-violet': '#3E3A7D', // Ajoute ta couleur personnalisée
        },
      },
    },
    plugins: [],
  }