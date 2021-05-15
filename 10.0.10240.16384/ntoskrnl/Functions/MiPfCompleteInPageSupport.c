// MiPfCompleteInPageSupport 
 
int __fastcall MiPfCompleteInPageSupport(int a1, int *a2, int a3, int a4)
{
  char v5; // r2
  int v6[2]; // [sp+8h] [bp-8h] BYREF

  v6[1] = a4;
  v6[0] = 0;
  if ( a2 != (int *)1 )
    goto LABEL_2;
  v5 = *(_BYTE *)(a1 + 113);
  if ( (v5 & 3) == 1 )
  {
    a2 = &dword_634E00;
LABEL_8:
    *(_BYTE *)(a1 + 113) = v5 & 0xFC;
LABEL_2:
    *(_BYTE *)(a1 + 115) |= 0x80u;
    return MiWaitForInPageComplete(a1, 0, (int)a2, 0, v6);
  }
  if ( (v5 & 3) != 2 )
  {
    if ( (v5 & 3) == 3 )
      a2 = &dword_634F00;
    goto LABEL_8;
  }
  return sub_54A944();
}
