#ifndef KFMElectrostaticLocalCoefficientCalculatorNumeric_HH__
#define KFMElectrostaticLocalCoefficientCalculatorNumeric_HH__

#include "KFMElectrostaticMultipoleCalculator.hh"

//vector math includes
#include "KVMField.hh"
#include "KVMFieldWrapper.hh"
#include "KVMLineSegment.hh"
#include "KVMPathIntegral.hh"
#include "KVMRectangularSurface.hh"
#include "KVMSurfaceIntegral.hh"
#include "KVMTriangularSurface.hh"


namespace KEMField
{

/*
*
*@file KFMElectrostaticLocalCoefficientCalculatorNumeric.hh
*@class KFMElectrostaticLocalCoefficientCalculatorNumeric
*@brief
*@details
*
*<b>Revision History:<b>
*Date Name Brief Description
*Thu Dec 19 14:52:58 EST 2013 J. Barrett (barrettj@mit.edu) First Version
*
*/

class KFMElectrostaticLocalCoefficientCalculatorNumeric : public KFMElectrostaticMultipoleCalculator
{
  public:
    KFMElectrostaticLocalCoefficientCalculatorNumeric();
    ~KFMElectrostaticLocalCoefficientCalculatorNumeric() override;

    void SetDegree(int l_max) override;

    virtual void SetNumberOfQuadratureTerms(unsigned int n);

    //constructs unscaled multipole expansion, assuming constant charge density
    //assumes a point cloud with 2 vertics is a wire electrode, 3 vertices is a triangle, and 4 is a rectangle/quadrilateral
    bool ConstructExpansion(double* target_origin, const KFMPointCloud<3>* vertices,
                            KFMScalarMultipoleExpansion* moments) const override;

  private:
    unsigned int fSize;

    virtual void IrregularSolidHarmonic(const double* point, double* result) const;

    KVMPathIntegral<2>* fNumInt1D;
    KVMSurfaceIntegral<2>* fNumInt2D;

    KVMFieldWrapper<KFMElectrostaticLocalCoefficientCalculatorNumeric,
                    &KFMElectrostaticLocalCoefficientCalculatorNumeric::IrregularSolidHarmonic>* fSolidHarmonicWrapper;

    //internal state to compute solid harmonic
    mutable double fOrigin[3];
    mutable double fDel[3];
    mutable double fL;
    mutable double fM;

    mutable std::vector<std::complex<double>> fMoments;

    mutable KVMLineSegment* fLine;
    mutable KVMTriangularSurface* fTriangle;
    mutable KVMRectangularSurface* fRectangle;

    mutable std::complex<double>* fSolidHarmonics;
};


}  // namespace KEMField


#endif /* KFMElectrostaticLocalCoefficientCalculatorNumeric_H__ */
