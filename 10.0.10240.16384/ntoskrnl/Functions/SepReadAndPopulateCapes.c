// SepReadAndPopulateCapes 
 
int __fastcall SepReadAndPopulateCapes(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // r4
  int v8; // [sp+2F4h] [bp-23Ch]

  v4 = ZwQueryKey();
  if ( v4 < 0 )
    return sub_816C54();
  if ( v8 )
    JUMPOUT(0x816CAE);
  *a4 = 0;
  *a3 = 0;
  return v4;
}
