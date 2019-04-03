var G = {};
G.dictionary = {};

const url = 'http://sheltercluster.lndo.site:8000/';

class Locale {

  static async init() {
    // Set initial language.
    G.language = 'en';

    // Load languages.
    const response = await axios.get(url + 'api-v1/app-languages');
    G.languages = response.data;
  }
    
  static async setLanguage(language) {
    G.language = language;
    console.log("Language set to", G.language);
    // Load language.
    const response = await axios.get(url + 'api-v1/app-translations/' + G.language + '.json');
    G.dictionary[G.language] = response.data;
  }

  static t(text, count = null, replacements = {}, count0 = null) {
    let count_replace = '@count';

    // If count = 0 and we provide a string for when count is 0.
    if (count === 0 && count0 !== null) {
      text = count0;
    }
    else if (count !== null) {
      // Get the plural index for languages with multiple plurals.
      const formula = G.languages[G.language].formula;
      const pluralIndex = eval(formula);

      if (pluralIndex > 0) {
        count_replace = '@count[' + pluralIndex + ']';
        text = text.replace('@count', count_replace);
      }
    }

    // Replace the text.
    const dictionary = G.dictionary[G.language];
    let translated_text = dictionary[text] || text;

    for (let i in replacements) {
      translated_text = translated_text.replace(i, replacements[i]);
    }
    
    // Replace @count for count.
    if (count !== null) {
      translated_text = translated_text.replace(count_replace, count);
    }

    return translated_text;
  }
  
}

Locale.init();
Locale.setLanguage('ar');
//Locale.t('@count example items', 11);

