// PspSetProcessAffinitySafe 
 
int __fastcall PspSetProcessAffinitySafe(int a1, char a2, __int16 *a3, int *a4, int *a5)
{
  int v5; // r6
  int v6; // r5
  char v7; // r7
  int v10; // r3
  int v11; // r4
  int v12; // r3
  __int16 v14[2]; // [sp+0h] [bp-30h] BYREF
  int v15; // [sp+4h] [bp-2Ch]
  int v16; // [sp+8h] [bp-28h]

  v5 = 1;
  v6 = 0;
  v7 = 0;
  if ( a4 )
  {
    v10 = *a4;
    v14[0] = 1;
    v14[1] = 1;
    a3 = v14;
    v15 = 0;
    v16 = v10;
    v7 = 1;
  }
  else if ( (a2 & 2) != 0 )
  {
    v7 = 2;
  }
  if ( (a2 & 1) != 0 )
  {
    v11 = 0;
  }
  else
  {
    v11 = *(_DWORD *)(a1 + 288);
    __dmb(0xBu);
    if ( v11 )
    {
      ExAcquireResourceSharedLite(v11 + 32, 1);
      v12 = *(_DWORD *)(v11 + 400);
      if ( (v12 & 0x10) != 0
        && ((v12 & 0x4000) == 0 || (*(_DWORD *)(v11 + 356) & *((_DWORD *)a3 + 2)) != *((_DWORD *)a3 + 2)) )
      {
        v5 = 0;
        goto LABEL_13;
      }
    }
  }
  v6 = KeSetAffinityProcess(a1, v7, a3);
LABEL_13:
  if ( v11 )
    ExReleaseResourceLite(v11 + 32);
  if ( v6 >= 0 )
    *a5 = v5;
  return v6;
}
