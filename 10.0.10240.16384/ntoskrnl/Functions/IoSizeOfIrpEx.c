// IoSizeOfIrpEx 
 
int __fastcall IoSizeOfIrpEx(int a1, __int16 a2)
{
  a2 = (char)a2;
  if ( a1 && (*(_DWORD *)(a1 + 28) & 0x8000000) != 0 )
    a2 = (char)(a2 + 1);
  return (unsigned __int16)(40 * a2 + 112);
}
