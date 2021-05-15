// sub_804B64 
 
void sub_804B64(int a1, int a2, int a3, int a4, ...)
{
  _DWORD *v4; // r4
  int v5; // r6
  int v6; // r7
  int v7; // r0
  _DWORD *v8; // r5
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  do
  {
    v7 = CmListGetPrevElement(v5 + 108, (int *)va);
    v8 = (_DWORD *)v7;
    if ( !v7 )
      goto LABEL_5;
  }
  while ( !CmEqualTrans(*(_DWORD *)(v7 + 28), v6) || v8[9] != 8 );
  *v4 = v8[12];
  v4[1] = v8[13];
LABEL_5:
  JUMPOUT(0x74D70E);
}
