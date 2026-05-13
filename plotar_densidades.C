#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h" 
#include "TLegend.h"
#include "TMultiGraph.h"

void plotar_densidades() {
    
    //Abre a janela do gráfico 
    TCanvas *c1 = new TCanvas("c1", "Comparacao Galactica", 800, 600);
    c1->SetGrid(); // Adiciona a grade

    // Gráfico do Halo
    TGraph *gHalo = new TGraph("dados_densidade_halo.txt");
    gHalo->SetLineColor(kAzure+1);
    gHalo->SetTitle("Halo Galactico");
    gHalo->SetLineWidth(1);

    // Gráfico do Disco
    TGraph *gDisco = new TGraph("dados_densidade_disco.txt");
    gDisco->SetLineColor(kRed);
    gDisco->SetTitle("Disco Galactico");
    gDisco->SetLineWidth(1);

    // Colocando os dois no MultiGraph
    TMultiGraph *mg = new TMultiGraph();
    mg->Add(gHalo);
    mg->Add(gDisco);
    mg->SetTitle("Estrutura da Via Lactea;z [kpc];Densidade relativa (n(z) / n_{0})");

    mg->Draw("AL"); // A = Eixos, L = Linha

    // Adiciona uma legenda para saber quem é quem
    TLegend *leg = new TLegend(0.7, 0.7, 0.9, 0.9);
    leg->AddEntry(gHalo, "Halo (z0=5kpc)", "l");
    leg->AddEntry(gDisco, "Disco (z0=0.2kpc)", "l");
    leg->Draw();

    c1->SaveAs("comparacao_estrutura_galactica.png");
}
