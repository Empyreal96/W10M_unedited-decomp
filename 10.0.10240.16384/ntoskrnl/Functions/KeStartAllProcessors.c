// KeStartAllProcessors 
 
int KeStartAllProcessors()
{
  int v0; // r0
  char v2[928]; // [sp+44h] [bp-3C0h] BYREF

  if ( (unsigned int)KeRegisteredProcessors > 0x20 )
    KeRegisteredProcessors = 32;
  KiBarrierWait = 1;
  memset(v2, 0, sizeof(v2));
  v0 = HalEnumerateProcessors(KeRegisteredProcessors);
  if ( !KeNumprocSpecified )
    JUMPOUT(0x966376);
  return sub_966370(v0);
}
