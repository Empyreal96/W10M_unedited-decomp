// _RegRtlOpenKeyTransacted 
 
int __fastcall RegRtlOpenKeyTransacted(int a1, unsigned __int16 *a2, char a3, int a4, int a5, int a6)
{
  int v6; // r5
  int v11; // r4
  int v12; // r3
  int v14; // [sp+0h] [bp-40h] BYREF
  char v15[8]; // [sp+8h] [bp-38h] BYREF
  int v16; // [sp+10h] [bp-30h]
  int v17; // [sp+14h] [bp-2Ch]
  char *v18; // [sp+18h] [bp-28h]
  int v19; // [sp+1Ch] [bp-24h]
  int v20; // [sp+20h] [bp-20h]
  int v21; // [sp+24h] [bp-1Ch]

  v6 = 0;
  v14 = 0;
  if ( RegRtlIsPredefinedKey() )
  {
    v11 = RegRtlOpenPredefinedKey(a1, &v14);
    if ( v11 < 0 )
    {
LABEL_10:
      v6 = v14;
      goto LABEL_11;
    }
    v6 = v14;
  }
  v11 = RtlInitUnicodeStringEx((int)v15, a2);
  if ( v11 >= 0 )
  {
    v12 = 64;
    if ( (a3 & 8) != 0 )
      v12 = 320;
    v16 = 24;
    if ( v6 )
      v17 = v6;
    else
      v17 = a1;
    v19 = v12 | 0x200;
    v18 = v15;
    v20 = 0;
    v21 = 0;
    if ( a6 )
      return sub_7C6AC0(a5, a4);
    v11 = ZwOpenKey();
    goto LABEL_10;
  }
LABEL_11:
  if ( v6 )
    ZwClose();
  return v11;
}
