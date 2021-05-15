// BiGetKeyName 
 
int __fastcall BiGetKeyName(int a1, int *a2)
{
  int v2; // r5
  int v3; // r0
  int v4; // r4
  int v5; // r0
  int v6; // r9
  int *v8; // [sp+10h] [bp-20h]

  v8 = a2;
  v2 = 0;
  v3 = BiZwQueryKey();
  v4 = v3;
  if ( v3 == -1073741789 )
  {
    v2 = ExAllocatePoolWithTag(1, 0, 1262764866);
    if ( !v2 )
      goto LABEL_5;
    v4 = BiZwQueryKey();
    if ( v4 < 0 )
      goto LABEL_9;
    v5 = ExAllocatePoolWithTag(1, *(_DWORD *)(v2 + 12) + 2, 1262764866);
    v6 = v5;
    if ( !v5 )
    {
LABEL_5:
      v4 = -1073741670;
      goto LABEL_9;
    }
    memmove(v5, v2 + 16, *(_DWORD *)(v2 + 12));
    *(_WORD *)(v6 + 2 * (*(_DWORD *)(v2 + 12) >> 1)) = 0;
    *v8 = v6;
  }
  else if ( v3 >= 0 )
  {
    v4 = -1073741811;
  }
LABEL_9:
  if ( v2 )
    ExFreePoolWithTag(v2);
  if ( v4 == -1073741443 )
    __debugbreak();
  return v4;
}
