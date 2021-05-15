// PipClearDevNodeUserFlags 
 
int __fastcall PipClearDevNodeUserFlags(int result, int a2)
{
  int v2; // r5
  int v3; // r3

  v2 = *(_DWORD *)(result + 272);
  v3 = v2 & ~a2;
  *(_DWORD *)(result + 272) = v3;
  if ( ((v3 ^ v2) & 0x47) != 0 )
    result = sub_7CB8D0();
  return result;
}
