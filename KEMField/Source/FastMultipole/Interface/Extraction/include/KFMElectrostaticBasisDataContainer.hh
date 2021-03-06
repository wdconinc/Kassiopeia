#ifndef KFMElectrostaticBasisDataContainer_HH__
#define KFMElectrostaticBasisDataContainer_HH__

#include "KBasis.hh"
#include "KElectrostaticBasis.hh"
#include "KFMBasisData.hh"
#include "KFMElectrostaticBasisDataExtractor.hh"
#include "KFMObjectContainer.hh"
#include "KSortedSurfaceContainer.hh"
#include "KSurfaceContainer.hh"
#include "KSurfaceTypes.hh"

namespace KEMField
{

/*
*
*@file KFMElectrostaticBasisDataContainer.hh
*@class KFMElectrostaticBasisDataContainer
*@brief
*@details
*
*<b>Revision History:<b>
*Date Name Brief Description
*Thu Apr 10 12:26:20 EDT 2014 J. Barrett (barrettj@mit.edu) First Version
*
*/

typedef KFMObjectContainer<KFMBasisData<1>> KFMElectrostaticBasisDataContainerPiecewiseConstant;

class KFMElectrostaticBasisDataContainer : public KFMElectrostaticBasisDataContainerPiecewiseConstant
{
  public:
    KFMElectrostaticBasisDataContainer(const KSurfaceContainer& container) :
        fSurfaceContainer(&container),
        fSortedSurfaceContainer(nullptr)
    {
        fContainerIsSorted = false;
    };

    KFMElectrostaticBasisDataContainer(const KSortedSurfaceContainer& container) :
        fSurfaceContainer(nullptr),
        fSortedSurfaceContainer(&container)
    {
        fContainerIsSorted = true;
    };

    ~KFMElectrostaticBasisDataContainer() override = default;
    ;

    unsigned int GetNObjects() const override
    {
        if (fContainerIsSorted) {
            return fSortedSurfaceContainer->size();
        }
        else {
            return fSurfaceContainer->size();
        }
    };

    void AddObject(const KFMBasisData<1>& /*obj*/) override
    {
        //warning...cannot add object to a virtual container
    }

    KFMBasisData<1>* GetObjectWithID(const unsigned int& id) override
    {
        if (fContainerIsSorted) {
            fSortedSurfaceContainer->at(id)->Accept(fBasisExtractor);
            double area = fSortedSurfaceContainer->at(id)->GetShape()->Area();

            //because the multipole library treats wires as 1-d elements
            //we only store the total charge of an element, and recompute the charge
            //density during the multipole calculation, as a linear or areal charge density
            fCurrentBasisData = fBasisExtractor.GetBasisData();
            fCurrentBasisData[0] = area * fCurrentBasisData[0];
            return &fCurrentBasisData;
        }
        else {
            fSurfaceContainer->at(id)->Accept(fBasisExtractor);
            double area = fSurfaceContainer->at(id)->GetShape()->Area();

            //because the multipole library treats wires as 1-d elements
            //we only store the total charge of an element, and recompute the charge
            //density during the multipole calculation, as a linear or areal charge density
            fCurrentBasisData = fBasisExtractor.GetBasisData();
            fCurrentBasisData[0] = area * fCurrentBasisData[0];
            return &fCurrentBasisData;
        }
    }

    const KFMBasisData<1>* GetObjectWithID(const unsigned int& id) const override
    {
        if (fContainerIsSorted) {
            fSortedSurfaceContainer->at(id)->Accept(fBasisExtractor);
            double area = fSortedSurfaceContainer->at(id)->GetShape()->Area();

            //because the multipole library treats wires as 1-d elements
            //we only store the total charge of an element, and recompute the charge
            //density during the multipole calculation, as a linear or areal charge density
            fCurrentBasisData = fBasisExtractor.GetBasisData();
            fCurrentBasisData[0] = area * fCurrentBasisData[0];
            return &fCurrentBasisData;
        }
        else {
            fSurfaceContainer->at(id)->Accept(fBasisExtractor);
            double area = fSurfaceContainer->at(id)->GetShape()->Area();

            //because the multipole library treats wires as 1-d elements
            //we only store the total charge of an element, and recompute the charge
            //density during the multipole calculation, as a linear or areal charge density
            fCurrentBasisData = fBasisExtractor.GetBasisData();
            fCurrentBasisData[0] = area * fCurrentBasisData[0];
            return &fCurrentBasisData;
        }
    }

    void DeleteAllObjects() override
    {
        ;
    };  //does nothing, no objects to delete


  private:
    const KSurfaceContainer* fSurfaceContainer;
    const KSortedSurfaceContainer* fSortedSurfaceContainer;
    bool fContainerIsSorted;

    mutable KFMElectrostaticBasisDataExtractor fBasisExtractor;
    mutable KFMBasisData<1> fCurrentBasisData;
};

}  // namespace KEMField


#endif /* KFMElectrostaticBasisDataContainer_H__ */
