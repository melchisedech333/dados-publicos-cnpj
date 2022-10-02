# Dados Públicos de CNPJ - Receita Federal

A Receita Federal disponibiliza os arquivos de dados públicos de CNPJ para pessoas interessadas em pesquisas e outras situações. Esta aplicação procura ajudar no download dos arquivos, realizando o mesmo de forma automática. Por algum motivo ao começar o download dos arquivos, eles são baixados em uma velocidade muito lenta, e em muitos casos (como o meu) chegam a travar o download, ao ponto de ter que recomeçar tudo novamente. Esta aplicação também resolve este problema, a mesma realiza os downloads normalmente, mas a cada 3 minutos eles são reiniciados (mas sempre continuando da parte em que estavam).


Requerimentos:
- Linux
- gcc
- wget
- aria2c


```bash
git clone https://github.com/melchisedech333/dados-publicos-cnpj.git
cd dados-publicos-cnpj
chmod +x links.sh
gcc downloader.c -o downloader -lpthread
./downloader 
```

Alternativas:

```bash
aria2c --file-allocation=none -c -x 16 -s 16 URL
```


