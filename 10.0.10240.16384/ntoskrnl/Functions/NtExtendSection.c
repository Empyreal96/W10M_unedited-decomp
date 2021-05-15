// NtExtendSection 
 
int __fastcall NtExtendSection(int a1, unsigned int a2)
{
  char v3; // r8
  int v4; // r2
  int v5; // r5
  int v7[2]; // [sp+10h] [bp-28h] BYREF
  int v8; // [sp+18h] [bp-20h]
  int v9; // [sp+1Ch] [bp-1Ch]
  int anonymous2; // [sp+40h] [bp+8h]
  unsigned int anonymous3; // [sp+44h] [bp+Ch]

  anonymous3 = a2;
  anonymous2 = a1;
  v3 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v3 )
  {
    if ( (a2 & 7) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a2 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a2 = *(_BYTE *)a2;
    v4 = *(_DWORD *)(a2 + 4);
    v8 = *(_DWORD *)a2;
    v9 = v4;
  }
  else
  {
    v8 = *(_DWORD *)a2;
    v9 = *(_DWORD *)(a2 + 4);
  }
  v5 = ObReferenceObjectByHandle(a1, 16, MmSectionObjectType, v3, (int)v7, 0);
  if ( v5 >= 0 )
  {
    v5 = MmExtendSection(v7[0]);
    v7[1] = v5;
    ObfDereferenceObject(v7[0]);
    *(_DWORD *)a2 = v8;
    *(_DWORD *)(a2 + 4) = v9;
  }
  return v5;
}
