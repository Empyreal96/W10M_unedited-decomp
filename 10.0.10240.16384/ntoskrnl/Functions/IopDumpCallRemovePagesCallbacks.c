// IopDumpCallRemovePagesCallbacks 
 
int __fastcall IopDumpCallRemovePagesCallbacks(int result, int a2)
{
  int v2; // r4
  int v3; // r5
  int v4; // r6
  int v5; // r9
  char v6; // r3
  char v7[4]; // [sp+0h] [bp-48h] BYREF
  int v8; // [sp+4h] [bp-44h]
  int v9[4]; // [sp+8h] [bp-40h] BYREF
  int v10; // [sp+18h] [bp-30h] BYREF
  int v11; // [sp+1Ch] [bp-2Ch]
  int v12; // [sp+20h] [bp-28h]
  int v13; // [sp+24h] [bp-24h]
  int v14; // [sp+28h] [bp-20h]
  int vars8; // [sp+50h] [bp+8h]
  int anonymous1; // [sp+54h] [bp+Ch]

  anonymous1 = a2;
  v2 = result;
  v8 = result;
  vars8 = result;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v3 = KeBugCheckAddRemovePagesCallbackListHead;
  v9[0] = (int)&KeBugCheckAddRemovePagesCallbackListHead;
  while ( 1 )
  {
    v9[1] = v3;
    if ( (int *)v3 == &KeBugCheckAddRemovePagesCallbackListHead )
      break;
    v9[2] = v3;
    result = KeValidateBugCheckCallbackRecord(v3, 6, v9);
    if ( result )
    {
      v10 = 0;
      v12 = v2;
      v4 = 0;
      do
      {
        v13 = 0;
        v11 = 0;
        v14 = 0;
        v5 = 0;
        v7[0] = 0;
        result = (*(int (__fastcall **)(int, int, int *, int))(v3 + 8))(6, v3, &v10, 20);
        v2 = v8;
        if ( v4 >= 0 && v14 )
        {
          result = IopRemovePageDumpRange(&v10, v7);
          v4 = result;
          v5 = (unsigned __int8)v7[0];
        }
      }
      while ( v5 );
      if ( v4 < 0 )
        v6 = 4;
      else
        v6 = 3;
      *(_BYTE *)(v3 + 24) = v6;
    }
    else if ( !v9[0] )
    {
      return result;
    }
    v3 = *(_DWORD *)v3;
  }
  return result;
}
