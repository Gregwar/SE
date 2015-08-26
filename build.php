<?php

include('vendor/autoload.php');

use Gregwar\Slidey\Slidey;

/**
 * Dossier dans lequel sera construit le site
 */
$targetDirectory = '../se/';

$slidey = new Slidey;

$slidey
    ->setTitle('Système embarqué')
    ->copy('img')
    ->copy('css')
    ->mkdir('files')
    ->copy(__DIR__.'/files/*.zip', 'files/')
    ->addCss('css/style.css')
    ->copy('favicon.ico')
    ;

$password = @include('password.php');
if ($password) {
    $slidey->enableInteractive($password, '/tmp/seslidey');
}

$slidey->build($targetDirectory);
