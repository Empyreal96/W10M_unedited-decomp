// MmGetFileNameForAddress 
 
int __fastcall MmGetFileNameForAddress(unsigned int a1, int a2)
{
  int v3; // r0
  int v4; // r4
  int v5; // r4
  int v6; // r0
  int v7; // r8
  unsigned int v8; // r7
  int v9; // r1
  int v10; // r0
  unsigned int v11; // r5
  unsigned __int16 v12; // r3
  unsigned int v14; // [sp+8h] [bp-20h] BYREF
  int v15[7]; // [sp+Ch] [bp-1Ch] BYREF

  v3 = MiObtainReferencedVad(a1, v15);
  v4 = v3;
  if ( !v3 )
    return -1073741503;
  if ( (*(_DWORD *)(v3 + 28) & 0x8000) != 0 || (v6 = **(_DWORD **)(v3 + 44), (*(_DWORD *)(v6 + 28) & 0x20) == 0) )
  {
    MiUnlockAndDereferenceVad(v4);
    v5 = -1073741751;
  }
  else
  {
    v7 = MI_REFERENCE_CONTROL_AREA_FILE(v6);
    MiUnlockAndDereferenceVad(v4);
    v8 = 1032;
    v9 = 1032;
    while ( 1 )
    {
      v10 = ExAllocatePoolWithTag(1, v9, 538996045);
      v11 = v10;
      if ( !v10 )
        break;
      v14 = 0;
      v5 = ObQueryNameStringMode(v7, v10, v8, &v14, 0);
      if ( v5 >= 0 )
      {
        v12 = *(_WORD *)v11;
        *(_DWORD *)(a2 + 4) = v11;
        *(_WORD *)(a2 + 2) = v12;
        *(_WORD *)a2 = v12;
        memmove(v11, *(_DWORD *)(v11 + 4), v12);
        goto LABEL_12;
      }
      ExFreePoolWithTag(v11);
      v9 = v14;
      if ( v14 <= v8 )
        goto LABEL_12;
      v8 = v14;
    }
    v5 = -1073741801;
LABEL_12:
    ObfDereferenceObject(v7);
  }
  return v5;
}
