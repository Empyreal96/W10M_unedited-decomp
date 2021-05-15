// DrvDbDispatchDriverDatabase 
 
int __fastcall DrvDbDispatchDriverDatabase(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int result; // r0
  int v8; // [sp+10h] [bp-18h] BYREF
  int v9[5]; // [sp+14h] [bp-14h] BYREF

  v8 = 0;
  result = PnpCtxGetObjectContext(a1, a3, &v8);
  if ( result >= 0 )
  {
    switch ( a4 )
    {
      case 1:
        result = DrvDbValidateDriverDatabaseName();
        break;
      case 2:
        result = DrvDbOpenDriverDatabaseRegKey(v8, a2, *a5, *((unsigned __int8 *)a5 + 4), a5[2], a5 + 3);
        break;
      case 3:
        v9[0] = 0;
        result = DrvDbOpenDriverDatabaseRegKey(v8, a2, *a5, 1, a5 + 1, v9);
        if ( result >= 0 )
          result = sub_818FC0();
        break;
      case 4:
        result = DrvDbDeleteDriverDatabase(v8, a2);
        break;
      case 5:
        result = DrvDbGetDriverDatabaseList(v8, *a5, a5[1], a5[2], a5[3], a5[4]);
        break;
      case 6:
        result = DrvDbGetDriverDatabaseMappedPropertyKeys(v8, a2, *a5, a5[3], a5[4], a5[5]);
        break;
      case 8:
        result = DrvDbGetDriverDatabaseMappedProperty(v8, a2, *a5, a5[2], a5[3], a5[4], a5[5], a5[6]);
        break;
      case 9:
        result = DrvDbSetDriverDatabaseMappedProperty(v8, a2, *a5, a5[2], a5[3], a5[4], a5[5]);
        break;
      default:
        result = -1073741811;
        break;
    }
  }
  return result;
}
