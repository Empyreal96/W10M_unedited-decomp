// PopFxEnumerateUnmaskedInterrupts 
 
int __fastcall PopFxEnumerateUnmaskedInterrupts(int a1, int a2, int a3, int a4, _WORD *a5)
{
  int v6; // [sp+0h] [bp-18h] BYREF
  int v7; // [sp+4h] [bp-14h]
  int v8; // [sp+8h] [bp-10h]
  int v9; // [sp+Ch] [bp-Ch]

  v6 = a1;
  v7 = a2;
  v8 = a3;
  v9 = a4;
  if ( !*a5 || (unsigned __int16)a5[1] < 0x1Cu )
    return -1073741811;
  v7 = a4;
  v8 = a1;
  v9 = a2;
  v6 = a3;
  return off_617AB4(PopFxEnumerateUnmaskedInterruptsCallback, &v6);
}
