// CmpRealignLogBuffers 
 
int __fastcall CmpRealignLogBuffers(int result)
{
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int v4; // r2
  int v5; // r3

  v1 = *(_DWORD *)(result + 12);
  switch ( v1 )
  {
    case 1:
    case 2:
      v2 = result + 52;
      *(_DWORD *)(result + 48) = *(unsigned __int16 *)(result + 32) + result + 52;
      goto LABEL_9;
    case 3:
    case 4:
    case 5:
      v3 = *(unsigned __int16 *)(result + 32);
      *(_DWORD *)(result + 36) = result + 60;
      v4 = result + 60 + v3;
      *(_DWORD *)(result + 44) = v4;
      if ( v1 != 5 )
        *(_DWORD *)(result + 56) = *(unsigned __int16 *)(result + 40) + v4;
      return result;
    case 6:
      v5 = result + 44;
      goto LABEL_6;
    case 7:
      v5 = result + 48;
LABEL_6:
      *(_DWORD *)(result + 36) = v5;
      break;
    case 8:
    case 9:
      v2 = result + 48;
      *(_DWORD *)(result + 44) = *(unsigned __int16 *)(result + 32) + result + 48;
LABEL_9:
      *(_DWORD *)(result + 36) = v2;
      break;
    default:
      return result;
  }
  return result;
}
