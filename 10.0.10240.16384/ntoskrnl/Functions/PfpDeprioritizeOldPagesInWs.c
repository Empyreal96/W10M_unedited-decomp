// PfpDeprioritizeOldPagesInWs 
 
int __fastcall PfpDeprioritizeOldPagesInWs(int a1, int a2)
{
  _DWORD *v2; // r6
  int v3; // r4
  unsigned int v4; // r3
  unsigned int v5; // r10
  unsigned int v6; // r8
  char v7; // r2
  _DWORD *v9; // [sp+10h] [bp-30h] BYREF
  int v10; // [sp+14h] [bp-2Ch]
  _DWORD v11[2]; // [sp+18h] [bp-28h] BYREF
  unsigned int v12; // [sp+20h] [bp-20h]
  int anonymous3; // [sp+48h] [bp+8h]
  int anonymous4; // [sp+4Ch] [bp+Ch]

  anonymous3 = a1;
  anonymous4 = a2;
  v10 = (char)a2;
  LOBYTE(anonymous4) = a2;
  v2 = 0;
  v9 = 0;
  if ( *(_DWORD *)(a1 + 16) == 12 )
  {
    if ( (_BYTE)a2 )
    {
      v4 = *(_DWORD *)(a1 + 12);
      if ( (v4 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( v4 + 12 > MmUserProbeAddress || v4 + 12 < v4 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    memmove((int)v11, *(_DWORD *)(a1 + 12), *(_DWORD *)(a1 + 16));
    if ( v11[0] != 3
      || (v12 & 0xFFFFFFC0) != 0
      || (v5 = v12 & 0xF, v5 > 8)
      || (v6 = (v12 >> 4) & 3, v6 == 3)
      || v5 == 8 && !v6 )
    {
      v3 = -1073741811;
    }
    else
    {
      v3 = ObReferenceObjectByHandleWithTag(v11[1], 0x2000, PsProcessType, v10, 1935107664, (int *)&v9, 0);
      if ( v3 < 0 )
      {
        v2 = v9;
      }
      else
      {
        v7 = 0;
        if ( v6 )
        {
          v7 = 1;
          if ( v6 == 1 )
            v7 = 3;
        }
        v2 = v9;
        v3 = MmUpdateOldWorkingSetPages(v9, v5, v7);
      }
    }
  }
  else
  {
    v3 = -1073741306;
  }
  if ( v2 )
    ObfDereferenceObjectWithTag((int)v2);
  return v3;
}
