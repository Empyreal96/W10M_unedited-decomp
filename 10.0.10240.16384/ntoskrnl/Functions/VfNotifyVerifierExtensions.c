// VfNotifyVerifierExtensions 
 
int __fastcall VfNotifyVerifierExtensions(int result, _DWORD *a2)
{
  int v2; // [sp+0h] [bp-20h] BYREF
  _DWORD *v3; // [sp+4h] [bp-1Ch]
  int v4; // [sp+8h] [bp-18h]
  int v5; // [sp+Ch] [bp-14h]
  int v6; // [sp+10h] [bp-10h]
  int v7; // [sp+14h] [bp-Ch]

  if ( ViFnXdvNotifyExtensions )
  {
    if ( result )
    {
      if ( (unsigned int)(result - 1) > 1 )
        return result;
      v2 = result;
      v3 = a2 + 11;
      v4 = a2[6];
      v5 = a2[8];
      v6 = a2[22];
      v7 = a2[16];
    }
    else
    {
      v2 = 0;
      v3 = a2;
    }
    result = ViFnXdvNotifyExtensions(&v2);
  }
  return result;
}
