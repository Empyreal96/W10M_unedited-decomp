// PipAreDriversLoadedWorker 
 
int __fastcall PipAreDriversLoadedWorker(int a1, int a2)
{
  int result; // r0

  while ( 2 )
  {
    switch ( a1 )
    {
      case 771:
      case 772:
      case 773:
      case 774:
      case 775:
      case 776:
      case 777:
      case 778:
      case 779:
      case 780:
      case 781:
      case 783:
      case 784:
      case 785:
      case 787:
        result = 1;
        break;
      case 782:
        a1 = a2;
        a2 = 768;
        continue;
      default:
        result = 0;
        break;
    }
    break;
  }
  return result;
}
