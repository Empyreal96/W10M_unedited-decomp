// HvpAllocateBin 
 
int __fastcall HvpAllocateBin(int a1, int a2, int a3, int a4, int a5, int *a6, int *a7)
{
  char v7; // r4
  int v10; // r5
  int v11; // r7
  int result; // r0
  int v14; // r1
  bool v15; // zf

  v7 = *(_BYTE *)(a1 + 72);
  v10 = 0;
  v11 = 0;
  *a7 = 0;
  *a6 = 0;
  if ( (v7 & 4) == 0 )
  {
    if ( !a3 )
    {
      v14 = 1;
LABEL_8:
      v10 = (*(int (__fastcall **)(int, int, int))(a1 + 12))(a2, v14, a5);
      v15 = v10 == 0;
      goto LABEL_9;
    }
LABEL_12:
    v14 = 0;
    goto LABEL_8;
  }
  if ( a3 )
    goto LABEL_12;
  if ( HvpCheckViewBoundary(a4, a2 + a4 - 1) )
  {
    v10 = HvViewMapAddressForFileOffset(a1 + 152, a4 + 4096);
LABEL_5:
    *a6 = v10;
    result = 0;
    *a7 = v11;
    return result;
  }
  v11 = (*(int (__fastcall **)(int, int, int))(a1 + 12))(a2, 1, a5);
  v15 = v11 == 0;
LABEL_9:
  if ( !v15 )
    goto LABEL_5;
  return -1073741670;
}
