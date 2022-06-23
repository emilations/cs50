var form = document.getElementById("myForm");
function handleForm(event) { event.preventDefault(); }
form.addEventListener("submit", handleForm);

document.querySelector("form").addEventListener("submit", thankfunction);

function thankfunction()
{
    document.querySelector("form").innerHTML = "Rquest submitted Successfully";
    alert('Thank you for submitting your request');
}