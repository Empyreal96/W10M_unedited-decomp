// IopDmaInitialize 
 
int IopDmaInitialize()
{
  dword_6303FC = (int)IopIrqUnpackRequirement;
  dword_630400 = (int)IopDmaPackResource;
  dword_630404 = (int)IopDmaUnpackResource;
  dword_630408 = (int)IopDmaScoreRequirement;
  dword_630448 = (int)HvlRegisterWheaErrorNotification;
  return ArbInitializeArbiterInstance();
}
