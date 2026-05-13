#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h" 

void plotar_densidade_disco() {
    
    TGraph *g = new TGraph("dados_densidade_disco.txt");

    //Título
    g->SetTitle("Perfil de Densidade Vertical (Disco);z [kpc];n(z) / n_{0}");
    g->SetLineWidth(1);

    //Cria a janela do gráfico
    TCanvas *c1 = new TCanvas("c1", "Densidade de Raios Cosmicos", 800, 600);

    g->SetMinimum(0); // Garante que o gráfico comece do zero no eixo Y
    g->SetMarkerStyle(7); // Adiciona pontinhos pequenos nos dados
    g->SetLineColor(kRed+1); // Cor do gráfico 

    c1->SetGrid();
    g->Draw("AC");
    
    //Salva o gráfico como imagem na pasta
    c1->SaveAs("perfil_densidade_disco.png");
}
