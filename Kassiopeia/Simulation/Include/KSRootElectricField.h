#ifndef Kassiopeia_KSRootElectricField_h_
#define Kassiopeia_KSRootElectricField_h_

#include "KGslErrorHandler.h"
#include "KSElectricField.h"
#include "KSList.h"

namespace Kassiopeia
{

class KSRootElectricField : public KSComponentTemplate<KSRootElectricField, KSElectricField>
{
  public:
    KSRootElectricField();
    KSRootElectricField(const KSRootElectricField& aCopy);
    KSRootElectricField* Clone() const override;
    ~KSRootElectricField() override;

  public:
    void CalculatePotential(const KThreeVector& aSamplePoint, const double& aSampleTime, double& aPotential) override;
    void CalculateField(const KThreeVector& aSamplePoint, const double& aSampleTime, KThreeVector& aField) override;
    void CalculateGradient(const KThreeVector& aSamplePoint, const double& aSampleTime,
                           KThreeMatrix& aGradient) override;
    void CalculateFieldAndPotential(const KThreeVector& aSamplePoint, const double& aSampleTime, KThreeVector& aField,
                                    double& aPotentia) override;

  public:
    void AddElectricField(KSElectricField* anElectricField);
    void RemoveElectricField(KSElectricField* anElectricField);

  private:
    double fCurrentPotential;
    KThreeVector fCurrentField;
    KThreeMatrix fCurrentGradient;

    KSList<KSElectricField> fElectricFields;

    static katrin::KGslErrorHandler& fGslErrorHandler;
};

}  // namespace Kassiopeia

#endif
