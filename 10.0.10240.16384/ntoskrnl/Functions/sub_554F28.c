// sub_554F28 
 
void __fastcall sub_554F28(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, char a10)
{
  _DWORD *v10; // r5
  _BYTE *v11; // r6
  int v12; // r7
  int v13; // r0

  if ( *(_DWORD *)(v12 + 92) < (unsigned int)SepAdtMinListLength )
  {
    *v11 = 0;
    if ( (unsigned int)KeGetCurrentIrql(a1) >= 2 )
    {
      v13 = ExAllocatePoolWithTag(512, 24);
      if ( v13 )
      {
        *(_DWORD *)(v13 + 8) = SepAdtGenerateDiscardAudit;
        *(_DWORD *)(v13 + 12) = v13;
        *(_DWORD *)v13 = 0;
        *(_DWORD *)(v13 + 16) = *v10;
        *(_BYTE *)(v13 + 20) = 1;
        ExQueueWorkItem((_DWORD *)v13, 1);
      }
    }
    else
    {
      a10 = 0;
      a9 = *v10;
      SepAdtGenerateDiscardAudit(&a5);
    }
    *v10 = 0;
    JUMPOUT(0x4F74C8);
  }
  ++SepAdtCountEventsDiscarded;
  JUMPOUT(0x4F74D6);
}
