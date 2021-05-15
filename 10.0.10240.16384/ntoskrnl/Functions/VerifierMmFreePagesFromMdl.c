// VerifierMmFreePagesFromMdl 
 
int __fastcall VerifierMmFreePagesFromMdl(int a1)
{
  int vars4; // [sp+Ch] [bp+4h]

  ViMmValidateIrql((MmVerifierData & 0x20000) != 0);
  if ( (MmVerifierData & 0x1000) != 0 )
    ViTargetAddToCounter(vars4, 120, 124, -*(_DWORD *)(a1 + 20));
  return pXdvMmFreePagesFromMdl(a1);
}
