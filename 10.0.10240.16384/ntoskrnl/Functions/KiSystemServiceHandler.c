// KiSystemServiceHandler 
 
int __fastcall KiSystemServiceHandler(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r12
  void *v5; // r4
  unsigned int v7; // r4
  int v8; // r0

  v4 = a1[1];
  if ( (v4 & 0x66) != 0 )
  {
    if ( (v4 & 0x20) == 0 )
    {
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( *(_BYTE *)(v7 + 346) )
        KiBugCheckDispatch(58, a2, a3, a4);
      v8 = *(_DWORD *)(v7 + 96);
      *(_DWORD *)(v7 + 96) = *(_DWORD *)(v8 + 8);
      *(_BYTE *)(v7 + 346) = *(_BYTE *)(v8 + 19);
    }
  }
  else
  {
    v5 = (void *)a1[3];
    if ( v5 == &loc_4219E8 || v5 >= &loc_421A34 && v5 < &loc_421A6C )
      a1 = (_DWORD *)RtlUnwindEx(a2, (int)KiSystemServiceExit, (int)a1, *a1, a3, 0);
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
      KiBugCheckDispatch(59, *a1, (int)a1, a3);
  }
  return 1;
}
