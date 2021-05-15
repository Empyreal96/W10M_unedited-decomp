// NtPrivilegeCheck 
 
int __fastcall NtPrivilegeCheck(int a1, unsigned int a2, _BYTE *a3, int a4)
{
  char v5; // r9
  int v6; // r0
  int v7; // r4
  int v8; // r8
  int v9; // r6
  int v10; // r10
  _BYTE *v11; // r2
  char v12; // r4
  int v15; // [sp+2Ch] [bp-2Ch] BYREF
  unsigned int v16; // [sp+30h] [bp-28h]
  int v17; // [sp+34h] [bp-24h]
  int varg_r0; // [sp+60h] [bp+8h]
  unsigned int varg_r1; // [sp+64h] [bp+Ch]
  _BYTE *varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v16 = 0;
  v5 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 8, SeTokenObjectType, v5, &v15);
  v7 = v6;
  if ( v6 >= 0 )
  {
    v8 = v15;
    if ( *(_DWORD *)(v15 + 168) == 2 && *(int *)(v15 + 172) < 1 )
    {
      v7 = -1073741659;
    }
    else
    {
      if ( (a2 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v6);
      if ( a2 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a2 = *(_BYTE *)a2;
      *(_BYTE *)(a2 + 16) = *(_BYTE *)(a2 + 16);
      v9 = *(_DWORD *)a2;
      if ( *(_DWORD *)a2 < -MmSystemRangeStart / 0xCu )
      {
        ProbeForWrite(a2, 12 * (*(_DWORD *)a2 - 1) + 20, 4);
        v11 = a3;
        if ( (unsigned int)a3 >= MmUserProbeAddress )
          v11 = (_BYTE *)MmUserProbeAddress;
        *v11 = *v11;
        v10 = *(_DWORD *)(a2 + 4);
      }
      else
      {
        v7 = -1073741811;
        v17 = -1073741811;
        v10 = 0;
      }
      if ( v7 >= 0 )
      {
        v7 = SeCaptureLuidAndAttributesArray(a2 + 8);
        if ( v7 >= 0 )
        {
          v12 = SepPrivilegeCheck(v8, 0, v9, v10, v5);
          ObfDereferenceObject(v8);
          memmove(a2 + 8, 0, v16);
          *a3 = v12;
          SeReleaseLuidAndAttributesArray(0, v5);
          return 0;
        }
      }
    }
    ObfDereferenceObject(v8);
  }
  return v7;
}
