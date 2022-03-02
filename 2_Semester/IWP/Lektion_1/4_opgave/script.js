let testWords = ["Hejsa", "med", "dig!"];

function wordLength(words){
    let totalLength = 0;

    for (let i = 0; i < words.length; i++) {
        
        totalLength += words[i].length;
    }

    return totalLength / words.length;
}