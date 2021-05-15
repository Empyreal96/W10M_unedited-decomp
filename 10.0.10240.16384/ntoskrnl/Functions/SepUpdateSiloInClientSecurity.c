// SepUpdateSiloInClientSecurity 
 
int __fastcall SepUpdateSiloInClientSecurity(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  __int64 v7; // kr00_8
  int v8; // r7
  int v9; // r6
  int v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  v5 = *(_DWORD *)(a1 + 12);
  v7 = *(_QWORD *)(v5 + 24);
  v8 = SeQueryServerSiloToken((int *)v5, v11);
  if ( v8 >= 0 )
  {
    if ( PsIsHostSilo(v11[0]) )
    {
      if ( v7 == 999 )
      {
        v8 = SepCopyClientTokenAndSetSilo(v5, *(_DWORD *)(a1 + 4), a2, v11);
        if ( v8 >= 0 )
        {
          v9 = v11[0];
          *(_BYTE *)(a1 + 16) = 0;
          *(_DWORD *)(a1 + 12) = v9;
          ObfDereferenceObject(v5);
          SeGetTokenControlInformation(v9, a1 + 20);
        }
      }
    }
  }
  return v8;
}
