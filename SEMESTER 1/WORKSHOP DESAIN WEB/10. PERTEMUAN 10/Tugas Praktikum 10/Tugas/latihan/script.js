//* Latihan
const list_items_1 = document.getElementById("list_keahlian");

const list_1 = ['Ux Desain', 'Web Developer', 'Video Editor'];

let parent = '<ol>';
list_1.forEach((keahlian) => {
  parent += '<li><strong>' + keahlian + '</strong></li>';
  console.log(`${keahlian}`);
});

parent += '</ol>';
list_items_1.innerHTML = parent;