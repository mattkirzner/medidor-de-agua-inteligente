document.addEventListener("DOMContentLoaded", function () {
    // Alternar o menu
    var menuIcon = document.querySelector('.menu-icon');
    var ul = document.querySelector('.ul');

    menuIcon.addEventListener('click', () => {
        ul.classList.toggle('ativo');
    });

    // Gerenciar envio do formulário
    const contactForm = document.getElementById('contactForm');
    const responseMessage = document.getElementById('responseMessage');

    contactForm.addEventListener('submit', function (event) {
        event.preventDefault();

        // Obter os valores dos campos
        const name = document.getElementById('name').value;
        const email = document.getElementById('email').value;
        const phone = document.getElementById('phone').value;
        const message = document.getElementById('message').value;

        // Simulação de envio
        if (name && email && message) {
            responseMessage.innerText = 'Mensagem enviada com sucesso!';
            responseMessage.style.display = 'block';
            responseMessage.style.color = 'green';

            // Limpar os campos após o envio
            contactForm.reset();
        } else {
            responseMessage.innerText = 'Por favor, preencha todos os campos obrigatórios.';
            responseMessage.style.display = 'block';
            responseMessage.style.color = 'red';
        }
    });  
    console.log("Script carregado");
});
