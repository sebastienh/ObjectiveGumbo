Pod::Spec.new do |s|
  s.name = 'ObjectiveGumbo'
  s.version = '0.1'
  s.license = 'Apache'
  s.summary = 'A simple way to parse HTML5 reliably with Cocoa'
  s.homepage = 'https://github.com/programmingthomas/ObjectiveGumbo'
  s.authors = {'Programming Thomas' => 'programmingthomas@gmail.com'}
  s.source = {:git => 'https://github.com/programmingthomas/ObjectiveGumbo.git'}
  s.source_files = 'ObjectiveGumbo/**'
  s.requires_arc = true
  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.7'
end