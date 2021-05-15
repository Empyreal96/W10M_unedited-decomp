// CmKeyBodyRemapToVirtual 
 
int __fastcall CmKeyBodyRemapToVirtual(int *a1)
{
  int v2; // r6
  int v3; // r0
  int v4; // r1
  unsigned int *v5; // r2
  unsigned int v6; // r3
  int v7; // r5
  int v8; // r3
  _DWORD *v9; // r0
  bool v10; // zf
  _DWORD *v11; // r0
  int v12; // r0
  _DWORD v14[2]; // [sp+10h] [bp-68h] BYREF
  int v15; // [sp+18h] [bp-60h] BYREF
  int v16[23]; // [sp+1Ch] [bp-5Ch] BYREF

  v15 = 0;
  v2 = 0;
  memset(v16, 0, 76);
  if ( CmpVEEnabled )
  {
    v3 = *(_DWORD *)(*a1 + 4);
    if ( (*(_WORD *)(v3 + 106) & 0x200) == 0 && !CmpIsMasterHive(v3) && !CmpIsSystemEntity(&v16[2], v4, v5, v6) )
    {
      v7 = *a1;
      v8 = *(_DWORD *)(*(_DWORD *)(*a1 + 4) + 104);
      if ( (v8 & 0x800000) != 0 && (v8 & 0x20) == 0 )
      {
        CmpLockRegistry();
        CmpLockKcbShared(*(_DWORD **)(*a1 + 4));
        v9 = *(_DWORD **)(*a1 + 4);
        if ( (v9[1] & 0x20000) != 0 )
        {
          CmpUnlockKcb(v9);
          v2 = -1073741444;
LABEL_12:
          CmpUnlockRegistry();
          return v2;
        }
        v10 = CmpReparseToVirtualPath(v9) == 0;
        v11 = *(_DWORD **)(*a1 + 4);
        if ( v10 )
        {
          CmpUnlockKcb(v11);
          v2 = 0;
          goto LABEL_12;
        }
        CmpUnlockKcb(v11);
        CmpUnlockRegistry();
        v15 = 8;
        v16[12] = *(_DWORD *)(v7 + 28);
        v12 = ObReferenceObjectByName((int)v14, 576, 0, 0, (int)CmKeyObjectType, 0, (int)&v15, a1);
        v2 = v12;
        if ( v12 < 0 )
          *a1 = v7;
        else
          ObfDereferenceObject(v7);
        RtlFreeAnsiString(v14);
      }
    }
  }
  return v2;
}
