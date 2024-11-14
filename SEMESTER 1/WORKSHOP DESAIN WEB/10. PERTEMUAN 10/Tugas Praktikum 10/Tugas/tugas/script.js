//* Tugas
const nama_element = document.getElementById("nama");
const user_logged = "Irvan Kurniawan";
nama_element.innerHTML = `Nama : ${user_logged}`;

const list_items_2 = document.getElementById("list_hobi");

const list_2 = ['Maen Game', 'Kuliner', 'Mancing'];

let parent_2 = '<ol>';
list_2.forEach((hobi) => {
  parent_2 += '<li><strong>' + hobi + '</strong></li>';
  console.log(`${hobi}`);
});

parent_2 += '</ol>';
list_items_2.innerHTML = parent_2;