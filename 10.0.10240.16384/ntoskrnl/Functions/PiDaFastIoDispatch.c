// PiDaFastIoDispatch 
 
int __fastcall PiDaFastIoDispatch(int a1)
{
  unsigned int v2; // r4
  int result; // r0
  __int16 *v4; // r5

  v2 = *(_DWORD *)(a1 + 12);
  result = 0;
  if ( v2 < 5 )
  {
    v4 = (&IrpHandlingTable)[3 * v2 + 1];
    if ( v4 )
      result = ((int (__fastcall *)(int))v4)(a1);
  }
  return result;
}
