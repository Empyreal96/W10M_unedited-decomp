// MiInsertNewProcess 
 
__int64 __fastcall MiInsertNewProcess(__int64 a1, int a2, int a3)
{
  int v3; // r5
  _DWORD *v4; // r7
  int v5; // r0
  int **v6; // r1
  _DWORD *v7; // r0
  _DWORD *v8; // r2
  __int64 v10; // [sp+0h] [bp-20h] BYREF
  int v11; // [sp+8h] [bp-18h]
  int v12; // [sp+Ch] [bp-14h]

  v10 = a1;
  v11 = a2;
  v12 = a3;
  v3 = HIDWORD(a1);
  v4 = (_DWORD *)a1;
  v5 = KeAcquireInStackQueuedSpinLock(&dword_634980, &v10);
  v6 = (int **)dword_6337D4;
  v4[155] = &dword_6337D0;
  v4[156] = v6;
  if ( *v6 != &dword_6337D0 )
    sub_510838(v5);
  *v6 = v4 + 155;
  dword_6337D4 = (int)(v4 + 155);
  if ( v3 )
  {
    v7 = *(_DWORD **)(v3 + 20);
    v8 = v4 + 58;
    v4[58] = v3 + 16;
    v4[59] = v7;
    if ( *v7 != v3 + 16 )
      __fastfail(3u);
    *v7 = v8;
    *(_DWORD *)(v3 + 20) = v8;
  }
  KeReleaseInStackQueuedSpinLock(&v10);
  return v10;
}
