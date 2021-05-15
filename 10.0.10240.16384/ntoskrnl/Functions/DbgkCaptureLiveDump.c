// DbgkCaptureLiveDump 
 
int __fastcall DbgkCaptureLiveDump(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r3
  int v5; // r10
  int v7; // r9
  int v8; // r2
  int v9; // r4
  int v10; // r6
  int v11; // r4
  int v12; // r1
  int v13; // r2
  int v14; // r3
  unsigned int v15; // r2
  _DWORD *v16; // r1
  unsigned int v17; // r2
  int v18; // r0
  int v19; // r0
  int v20; // r0
  unsigned int v23; // [sp+8h] [bp-118h]
  int *v24; // [sp+Ch] [bp-114h]
  int v26; // [sp+10h] [bp-110h]
  int v28; // [sp+24h] [bp-FCh] BYREF
  _DWORD v29[3]; // [sp+28h] [bp-F8h] BYREF
  int v30; // [sp+34h] [bp-ECh]
  char v31[128]; // [sp+38h] [bp-E8h] BYREF
  int v32[8]; // [sp+B8h] [bp-68h] BYREF
  int v33[6]; // [sp+D8h] [bp-48h] BYREF
  int v34[12]; // [sp+F0h] [bp-30h] BYREF

  v4 = a3;
  v5 = 0;
  v7 = 0;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v9 = a1[7];
  v10 = 0;
  v30 = v8;
  if ( !v9 || v4 < 0x20000 || (*a1 & 0xFFFFFFFE) != 0 )
    return -1073741811;
  if ( DbgkpLkmdSqmIsOptedIn() )
    EtwRegister((int)dword_406D28, 0, 0);
  memset(v32, 0, sizeof(v32));
  v11 = DbgkpTriageDumpInitialize(v32, a2, a3, v33);
  if ( v11 >= 0 )
  {
    v11 = ((int (__fastcall *)(int *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v33[0])(
            v32,
            a1[1],
            a1[2],
            a1[3],
            a1[4],
            a1[5]);
    if ( v11 >= 0 )
    {
      DbgkpLkmdSnapGlobals((int)v31, v12, v13, v14);
      v10 = ExAllocatePoolWithTag(1, 4 * (a1[7] + 1), 1884181323);
      if ( v10 )
      {
        v15 = 0;
        if ( a1[7] )
        {
          v16 = (_DWORD *)v10;
          do
          {
            *v16++ = -1073741823;
            ++v15;
          }
          while ( v15 < a1[7] );
        }
        *(_DWORD *)(v10 + 4 * v15) = 1112752980;
      }
      v26 = 1;
      v17 = 0;
      v11 = -1073741790;
      v23 = 0;
      if ( a1[7] )
      {
        v24 = (int *)v10;
        while ( 1 )
        {
          v34[2] = 0;
          v34[3] = 0;
          v34[0] = -1073741823;
          v34[1] = 0;
          v18 = ObReferenceObjectByHandle(
                  *(_DWORD *)(a1[8] + 4 * (v17 + a1[6])),
                  0x1FFFFF,
                  PsThreadType,
                  v30,
                  (int)&v28,
                  0);
          v5 = v28;
          if ( v18 != -1073741790 )
            v26 = 0;
          if ( v18 >= 0 )
          {
            if ( !v7 )
            {
              v19 = IoThreadToProcess(v28);
              v7 = v19;
              if ( v19 )
              {
                ObfReferenceObjectWithTag(v19);
                DbgkpLkmdSnapDataEx((int)v31);
              }
            }
            v20 = DbgkpLkmdSnapThread((int)v31, (int)a1, v5, (int)v34);
            if ( !v20 )
              v20 = v34[0];
            if ( v10 )
              *v24 = v20;
            DbgkpLkmdFireCallbacks(v31, 2, v5);
            ObfDereferenceObject(v5);
            v5 = 0;
            if ( v34[0] == -1073741670 )
            {
LABEL_31:
              if ( !v26 )
              {
                if ( v7 )
                  DbgkpLkmdFireCallbacks(v31, 1, v7);
                v29[0] = a1[7];
                v29[1] = v10;
                DbgkpLkmdSnapData((int)v31);
                if ( v10 )
                  DbgkpLkmdSnapData((int)v31);
                if ( DbgkpLkmdSnapDataEx((int)v31) >= 0 )
                  *(_DWORD *)v29[2] = v29;
                v11 = ((int (__fastcall *)(int *, int))v33[5])(v32, a4);
              }
              break;
            }
          }
          else if ( v10 )
          {
            *v24 = v18;
          }
          ++v24;
          v17 = v23 + 1;
          v23 = v17;
          if ( v17 >= a1[7] )
            goto LABEL_31;
        }
      }
      if ( v7 )
        ObfDereferenceObjectWithTag(v7);
      if ( v5 )
        ObfDereferenceObject(v5);
    }
  }
  if ( v32[6] )
    ExFreePoolWithTag(v32[6]);
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v11;
}
