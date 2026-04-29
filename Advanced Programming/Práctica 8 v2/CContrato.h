#if !defined(_CONTRATO_H)
#define _CONTRATO_H

#include <iostream>
#include <string>
#include "CSiniestro.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include <vector>

using namespace std;

class CContrato
{
    friend ostream& operator<<(ostream& os, CContrato& c);
private:
    int m_NumSerie;
    std::string m_Descripcion;
    std::string m_FechaFin;
    long m_Poliza;
    long m_ValorCompra;
    vector<CSiniestro*> m_Siniestros;

public:
    CContrato(int NumSerie, const std::string& Desc = "", const std::string& FF = "", // CONSTRUCTOR
        long Poliza = 0, long ValorCompra = 0);

    CContrato(const CContrato& c); // constructor copia
    CContrato& operator=(const CContrato& c); // operador de asignacion
    ~CContrato();

    void SetNumSerie(int ns) { m_NumSerie = ns; }
    void SetDescripcion(const std::string& d) { m_Descripcion = d; }
    void SetFechaFin(const std::string& ff) { m_FechaFin = ff; }
    void SetPoliza(long p) { m_Poliza = p; }
    void SetValorCom(long vc) { m_ValorCompra = vc; }

    int GetNumSerie() const { return m_NumSerie; }
    std::string GetDescripcion() const { return m_Descripcion; }
    std::string GetFechaFin() const { return m_FechaFin; }
    long GetPoliza() const { return m_Poliza; }
    long GetValorCom() const { return m_ValorCompra; }
    void AgregarSiniestro(const CSiniestro& s);
    void MostrarSiniestros(std::ostream& os = std::cout);
    void BorrarSiniestros();
};

#endif