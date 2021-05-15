// SmProcessStoreMemoryPriorityRequest 
 
int __fastcall SmProcessStoreMemoryPriorityRequest(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r10
  int v6; // r4
  int v7; // r8
  int v8; // r3
  int v9; // r0
  int v11; // [sp+0h] [bp-50h] BYREF
  int v12; // [sp+4h] [bp-4Ch] BYREF
  int v13; // [sp+8h] [bp-48h]
  int v14; // [sp+Ch] [bp-44h]
  int v15; // [sp+10h] [bp-40h]
  _DWORD _18[18]; // [sp+18h] [bp-38h] BYREF
  int varg_r2; // [sp+60h] [bp+10h]
  int varg_r3; // [sp+64h] [bp+14h]

  _18[16] = a1;
  _18[17] = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  LOBYTE(varg_r2) = a3;
  v4 = 0;
  v11 = 0;
  v5 = 0;
  v15 = 0;
  v13 = 0;
  v14 = 0;
  if ( a2 == 8 )
  {
    if ( (_BYTE)a3 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a1 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)a1 = *(_BYTE *)a1;
      *(_BYTE *)(a1 + 4) = *(_BYTE *)(a1 + 4);
    }
    v13 = *(_DWORD *)a1;
    v7 = *(_DWORD *)(a1 + 4);
    v14 = v7;
    if ( (unsigned __int8)v13 == 1 )
    {
      if ( (v13 & 0xFFFFFE00) != 0 )
      {
        v6 = -1073741811;
      }
      else if ( (v13 & 0x100) != 0 )
      {
        v6 = SmRereferenceProcessObject(v7, 8, a3, &v11);
        if ( v6 < 0 )
        {
          v4 = v11;
        }
        else
        {
          v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v4 = v11;
          if ( v8 != v11 )
          {
            v5 = 1;
            KiStackAttachProcess(v11, 0, (int)_18);
          }
          v12 = v4;
          v9 = SmpKeyedStoreEntryGet((int)&unk_636CC4, (int)&v12, 0, 0);
          if ( v9 )
            v6 = SMKM_STORE_MGR<SM_TRAITS>::SmPrioritizeRegionsStore(
                   (int)SmGlobals,
                   SmGlobals[24 * (*(_WORD *)(v9 + 8) & 0x1F)]);
          else
            v6 = -1073741632;
        }
      }
      else
      {
        v6 = -1073741637;
      }
    }
    else
    {
      v6 = -1073741735;
    }
  }
  else
  {
    v6 = -1073741306;
  }
  if ( v5 )
    KiUnstackDetachProcess((unsigned int)_18, 0);
  if ( v4 )
    ObfDereferenceObject(v4);
  return v6;
}
