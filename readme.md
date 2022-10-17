
<div align='center'>

<img src="images/banner.jpg" width="100%" >

</div>

<br>

<p align="center">
    <a href="https://github.com/sponsors/melchisedech333"><img src="https://img.shields.io/badge/sponsor-30363D?style=for-the-badge&logo=GitHub-Sponsors&logoColor=#white" ></a>
    <br><br>
    <img src="https://badgen.net/badge/love level/6 of 10/purple" >
    <img src="https://img.shields.io/github/languages/count/melchisedech333/dados-publicos-cnpj?color=%23f34b7d" >
    <img src="https://img.shields.io/github/languages/top/melchisedech333/dados-publicos-cnpj?color=%23f34b7d" >
    <img src="https://img.shields.io/github/directory-file-count/melchisedech333/dados-publicos-cnpj" >
    <img src="https://img.shields.io/github/repo-size/melchisedech333/dados-publicos-cnpj" >
    <img src="https://img.shields.io/github/license/melchisedech333/dados-publicos-cnpj" >
</p>

<br>

<b>Note:</b> this document is written in PT-BR 🇧🇷

A Receita Federal disponibiliza os arquivos de dados públicos de CNPJ para pessoas interessadas em pesquisas e outras situações. Esta aplicação procura ajudar no download dos arquivos, realizando o mesmo de forma automática. Por algum motivo ao começar o download dos arquivos, eles são baixados em uma velocidade muito lenta, e em muitos casos (como o meu) chegam a travar o download, ao ponto de ter que recomeçar tudo novamente. Esta aplicação também resolve este problema, a mesma realiza os downloads normalmente, mas a cada 3 minutos eles são reiniciados (mas sempre continuando da parte em que estavam).

**Se meu código te ajudou em algo, considere [ser um patrocinador](https://github.com/sponsors/melchisedech333) :blue_heart:** 

<br>

<b>Requerimentos:</b>
- Linux
- gcc
- wget
- aria2c

<br>

Para utilizar a aplicação, basta realizar os passos abaixo.

```bash
git clone https://github.com/melchisedech333/dados-publicos-cnpj.git
cd dados-publicos-cnpj
chmod +x links.sh
gcc downloader.c -o downloader -lpthread
./downloader 
```

<br>

Além de utilizar esta aplicação, você pode contar com esta alternativa abaixo. Onde em <b>URL</b> você insere um link por vez (eles estão contidos no arquivo <b>links.sh</b>)

O legal do aria2c é que ele baixa utilizando multi-threading, então a depender da sua situação, pode ser mais rápido utilizá-lo.

```bash
aria2c --file-allocation=none -c -x 16 -s 16 URL
```


<br>

:smiley: Autor
---

Patrocinar: [melchisedech333](https://github.com/sponsors/melchisedech333)<br>
Twitter: [Melchisedech333](https://twitter.com/Melchisedech333)<br>
LinkedIn: [Melchisedech Rex](https://www.linkedin.com/in/melchisedech-rex-724152235/)<br>
Blog: [melchisedech333.github.io](https://melchisedech333.github.io/)<br>

<a href="https://github.com/melchisedech333" ><img src="https://github.com/melchisedech333.png?size=200" height="100" /></a>

<br>

:scroll: Licença
---

[ BSD-3-Clause license](./license)

<br><br>

<div align="center">

## Lembre-se de deixar <br> uma linda estrelinha :star_struck:

</div>


