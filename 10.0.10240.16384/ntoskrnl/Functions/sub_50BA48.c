// sub_50BA48 
 
void __fastcall sub_50BA48(_DWORD *a1)
{
  int v1; // r5
  int v2; // r7
  int v3; // r9

  if ( !*(_WORD *)(v1 + 310) && !v2 )
  {
    __dmb(0xBu);
    *a1 = v3;
    KfLowerIrql(1);
    KiDeliverApc(0, 0, 0);
    KfRaiseIrql(2);
    *(_BYTE *)(v1 + 134) = 0;
    JUMPOUT(0x464FE6);
  }
  JUMPOUT(0x46501E);
}
